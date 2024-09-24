#include "Graph.hpp"
#include <png.h>
#include <fstream>
#include <sstream>

Graph::Graph(int p_size, const std::string filename) : size(p_size)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file: " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string x_str, y_str;

		if (std::getline(ss, x_str, ';') && std::getline(ss, y_str)) {
			float x, y;
			std::stringstream x_stream(x_str);
			std::stringstream y_stream(y_str);

			if ((x_stream >> x) && (y_stream >> y)) {
				addVector(x, y);
			} else {
				std::cerr << "Error parsing point from line: " << line << std::endl;
			}
		} else {
			std::cerr << "Error: Invalid line format: " << line << std::endl;
		}
	}

	file.close();
}



void Graph::toPNG(const std::string filename) const {
	FILE *fp = fopen(filename.c_str(), "wb");
	if (!fp) {
		std::cerr << "Error opening file" << std::endl;
		return;
	}

	// initialize write struct
	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png) {
		std::cerr << "Error creating write struct" << std::endl;
		fclose(fp);
		return;
	}

	// initialize info struct 
	png_infop info = png_create_info_struct(png);
	if (!info) {
		std::cerr << "Error creating info struct" << std::endl;
		png_destroy_write_struct(&png, NULL);
		fclose(fp);
		return;
	}

	// set up error handling
	if (setjmp(png_jmpbuf(png))) {
		std::cerr << "Error during init_io" << std::endl;
		png_destroy_write_struct(&png, &info);
		fclose(fp);
		return;
	}

	// set up output control
	png_init_io(png, fp);

	// set image attributes
	png_set_IHDR( png, info, size, size,
		8,
		PNG_COLOR_TYPE_RGB,
		PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_DEFAULT,
		PNG_FILTER_TYPE_DEFAULT
	);

	png_write_info(png, info);

	// allocate memory for one row (3 bytes per pixel - RGB)
	png_bytep row = (png_bytep) malloc(3 * size * sizeof(png_byte));

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (vectorExists(Vector2(x, y))) {
				row[x * 3] = 0;
				row[x * 3 + 1] = 255;
				row[x * 3 + 2] = 0;
			} else {
				row[x * 3] = 255;
				row[x * 3 + 1] = 255;
				row[x * 3 + 2] = 255;
			}
		}
		png_write_row(png, row);
	}

	png_write_end(png, NULL);

	free(row);
	png_destroy_write_struct(&png, &info);
	fclose(fp);
}

void Graph::drawLine(const float x1, const float y1, const float x2, const float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	// Determine the number of steps
	int steps = std::max(std::abs(dx), std::abs(dy));

	// Calculate the increment values for each step
	float xIncrement = dx / steps;
	float yIncrement = dy / steps;

	float x = x1;
	float y = y1;

	addVector(round(x), round(y));

	// Generate points using the DDA algorithm
	for (int i = 0; i < steps; i++) {
		x += xIncrement;
		y += yIncrement;
		addVector(round(x), round(y));
	}
}


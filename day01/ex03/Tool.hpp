#ifndef TOOL_HPP
# define TOOL_HPP

class Worker;

class Tool
{
	friend class Worker;

	protected:
		virtual void	setOwner(Worker *) = 0;
		virtual void	Use() = 0;
};

#endif

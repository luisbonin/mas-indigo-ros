/**
 *  TaskPriorities.cpp
 *
 *  Version: 1.2.4
 *  Created on: 04/04/2016
 *  Modified on: 17/08/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "mas/tasks/TaskPriorities.h"

namespace mas
{
	namespace tasks
	{

		/**
		 *
		 */
		TaskPriorityEnum TaskPriorities::toEnumerated(int code)
		{
			TaskPriorityEnum enumerated;
			switch (code)
			{
				case 1:
					enumerated = priorities::LOW;
					break;
				case 2:
					enumerated = priorities::NORMAL;
					break;
				case 3:
					enumerated = priorities::IMPORTANT;
					break;
				case 4:
					enumerated = priorities::CRITICAL;
					break;
				default:
					enumerated = getDefault();
			}
			return enumerated;
		}

		/**
		 *
		 */
		TaskPriorityEnum TaskPriorities::toEnumerated(std::string name)
		{
		  TaskPriorityEnum enumerated;
		  if (name == "LOW" || name == "Low" || name == "low")
		  {
		    enumerated = priorities::LOW;
		  }
		  else if (name == "NORMAL" || name == "Normal" || name == "normal")
		  {
		    enumerated = priorities::NORMAL;
		  }
		  else if (name == "IMPORTANT" || name == "Important" || name == "important")
		  {
		    enumerated = priorities::IMPORTANT;
		  }
		  else if (name == "CRITICAL" || name == "Critical" || name == "critical")
		  {
		    enumerated = priorities::CRITICAL;
		  }
		  else
		  {
		    enumerated = getDefault();
		  }
		  return enumerated;
		}

		/**
		 *
		 */
		bool TaskPriorities::isValid(std::string name)
		{
		  return name == "LOW"       || name == "Low"       || name == "low"      ||
			    name == "NORMAL"    || name == "Normal"    || name == "normal"   ||
			    name == "IMPORTANT" || name == "Important" || name == "important"||
			    name == "CRITICAL"  || name == "Critical"  || name == "critical";
		}

		/**
		 *
		 */
		int TaskPriorities::toCode(TaskPriorityEnum enumerated)
		{
			int code;
			switch (enumerated)
			{
				case priorities::LOW:
					code = 1;
					break;
				case priorities::NORMAL:
					code = 2;
					break;
				case priorities::IMPORTANT:
					code = 3;
					break;
				case priorities::CRITICAL:
					code = 4;
					break;
				default:			
					code = toCode(getDefault());
			}
			return code;
		}

		/**
		 *
		 */
		std::string TaskPriorities::toString(TaskPriorityEnum enumerated)
		{
			std::string enumerated_name;
			switch (enumerated)
			{
				case priorities::LOW:
					enumerated_name = "LOW";
					break;
				case priorities::NORMAL:
					enumerated_name = "NORMAL";
					break;
				case priorities::IMPORTANT:
					enumerated_name = "IMPORTANT";
					break;
				case priorities::CRITICAL:
					enumerated_name = "CRITICAL";
					break;
				default:
					enumerated_name = toString(getDefault());
			}
			return enumerated_name;
		}

		/**
		 *
		 */
		TaskPriorityEnum TaskPriorities::getDefault()
		{
			return priorities::LOW;
		}

		/**
		 *
		 */
		std::vector<TaskPriorityEnum> TaskPriorities::getAll()
		{
		  std::vector<TaskPriorityEnum> enumerateds;
		  enumerateds.push_back(priorities::LOW);
		  enumerateds.push_back(priorities::NORMAL);
		  enumerateds.push_back(priorities::IMPORTANT);
		  enumerateds.push_back(priorities::CRITICAL);
		  return enumerateds;
		}

		/**
		 *
		 */
		int TaskPriorities::compare(TaskPriorityEnum priority1, TaskPriorityEnum priority2)
		{
		  int code1 = toCode(priority1);
		  int code2 = toCode(priority2);
		  return code1 - code2;
		}
		
	}
}

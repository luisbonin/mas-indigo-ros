/**
 *  Allocation.h
 *
 *  Version: 1.2.4
 *  Created on: 04/08/2015
 *  Modified on: 17/08/2016
 *  Authors: Adriano Henrique Rossette Leite (adrianohrl@unifei.edu.br)
 *           Heverton Machado Soares (sm.heverton@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef TASKS_ALLOCATION_H_
#define TASKS_ALLOCATION_H_

#include <mas_msgs/Allocation.h>
#include "mas/agents/Robot.h"
#include "mas/tasks/Task.h"
#include "mas/tasks/AllocationSatisfactions.h"
#include "mas/tasks/AllocationStates.h"

namespace mas 
{
	namespace tasks
	{
		class Allocation 
		{
		public:
			Allocation();
			Allocation(Task task, std::vector<agents::Robot> robots, AllocationStateEnum state, AllocationSatisfactionEnum satisfaction, ros::Time allocation_timestamp, ros::Time dispatch_timestamp, ros::Time start_timestamp, ros::Time end_timestamp);
			Allocation(Task task, std::vector<agents::Robot> robots = std::vector<agents::Robot>());
			Allocation(const mas_msgs::Allocation::ConstPtr& allocation_msg);
			Allocation(mas_msgs::Allocation allocation_msg);		
			~Allocation();

			Task getTask();
			std::vector<agents::Robot> getRobots();
			AllocationStateEnum getState();
			AllocationSatisfactionEnum getSatisfaction();
			ros::Time getAllocationTimestamp();
			ros::Time getDispatchTimestamp();
			ros::Time getStartTimestamp();
			ros::Time getEndTimestamp();
			bool wasAllocated();
			bool wasDispatched();
			bool wasAccepted();
			bool isExecuting();
			bool isFinished();
			bool wasSucceeded();
			bool wasAborted();
			bool wasCancelled();
			bool wasEvaluated();
			void setSatisfaction(AllocationSatisfactionEnum satisfaction);
			void allocate(std::vector<agents::Robot> robots);
			void dispatch();
			void start();
			void end();
			void abort();
			void cancel();
			bool finish(AllocationStateEnum state);
			bool isInvolved(agents::Robot robot);
			bool isInvolved(agents::Person person);
			mas_msgs::Allocation toMsg();
			std::string toString();
			int compareTo(Allocation allocation);
			bool equals(const Allocation& allocation);
			bool operator==(const Allocation& allocation);
			bool operator!=(const Allocation& allocation);
			void operator=(const Allocation& allocation);

		private:
			Task task_;
			std::vector<agents::Robot> robots_;
			AllocationStateEnum state_;
			AllocationSatisfactionEnum satisfaction_;
			ros::Time allocation_timestamp_;
			ros::Time dispatch_timestamp_;
			ros::Time start_timestamp_;
			ros::Time end_timestamp_;

			void addRobots(std::vector<agents::Robot> robots);
			void addRobot(agents::Robot robot);
			void removeRobot(agents::Robot robot);
			bool isValid(AllocationStateEnum state);
			void setState(AllocationStateEnum state);
			bool hasStateChanged(AllocationStateEnum state);
			void setAllocationTimestamp(ros::Time allocation_timestamp = ros::Time::now());
			void setDispatchTimestamp(ros::Time dispatch_timestamp = ros::Time::now());
			void setStartTimestamp(ros::Time start_timestamp = ros::Time::now());
			void setEndTimestamp(ros::Time end_timestamp = ros::Time::now());
			
		};
	}
}		

#endif /* TASKS_ALLOCATION_H_ */

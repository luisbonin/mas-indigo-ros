/**
 *  S8DeadlineVerificationState.h
 *
 *  Version: 1.2.4
 *  Created on: 14/05/2016
 *  Modified on: 17/08/2016
 *  Authors: Adriano Henrique Rossette Leite (adrianohrl@unifei.edu.br)
 *           Luís Victor Pessiqueli Bonin (luis-bonin@hotmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef TASK_BUILDER_S8_DEADLINE_VERIFICATION_STATE_H_
#define TASK_BUILDER_S8_DEADLINE_VERIFICATION_STATE_H_

#include "mas/tasks/TaskPriorities.h"
#include "mas/tasks/task_builder/AbstractState.h"
#include "utilities/TimeManipulator.h"

#define DEFAULT_DURATION 3600

namespace mas
{
	namespace tasks
	{
		namespace task_builder
		{
			class S8DeadlineVerificationState : public AbstractState
			{

			public:
				S8DeadlineVerificationState(MachineController* controller);
				virtual ~S8DeadlineVerificationState();

				virtual bool process(std::string answer);
				virtual std::string toString();

	 		private:
				virtual bool next(std::string answer);

			};
		}
	}		
}
					
#endif /* TASK_BUILDER_S8_DEADLINE_VERIFICATION_STATE_H_ */

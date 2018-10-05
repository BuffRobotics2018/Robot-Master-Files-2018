#pragma config(Motor,  port2,           arm,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           drive,         tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task armMove()
{// Moves arm forward while Btn5U is pressed, and backwards while Btn6U is pressed //

	while(true)// Program will constantly check for these events //
	{

		bool leftTriggerU;
		bool rightTriggerU;

		while(vexRT[Btn5U])// While Btn5U is pressed, set boolean variable "leftTrigger" to true //
		{

			leftTriggerU = true;

		}

		while(vexRT[Btn5U] == false)// While Btn5U is NOT pressed, set boolean variable "leftTrigger" to false //
		{

			leftTriggerU = false;

		}

		while(vexRT[Btn6U])// While Btn6U is pressed, set boolean variable "rightTrigger" to true //
		{

			rightTriggerU = true;

		}

		while(vexRT[Btn6U] == false)// While Btn6U is NOT pressed, set boolean variable "rightTrigger" to false //
		{

			rightTriggerU = false;

		}

		while (leftTriggerU == true)// While the boolean variable "leftTrigger" is true, set motor "drive" speed to 127 //
		{

			motor[drive] = 127;

		}

		while (rightTriggerU)// While the boolean variable "rightTrigger" is true, set motor "drive" speed to -127 //
		{

			motor[drive] = -127;

		}

		while((rightTriggerU == false) && (leftTriggerU == false))// While both boolean variables are false, stop motor "drive" //
		{

			stopMotor(arm);

		}

		while((rightTriggerU == true) && (leftTriggerU == true))// While both boolean variables are true, stop motor "drive" //
		{

			stopMotor(arm);

		}

	}

}

task driveMotor()
{

	while(true)
	{

		bool leftTriggerD;
		bool rightTriggerD;

		while(vexRT[Btn5D])
		{

			leftTriggerD = true;

		}

		while(vexRT[Btn5D] == false)
		{

			leftTriggerD = false;

		}

		while(vexRT[Btn6D])
		{

			rightTriggerD = true;

		}

		while(vexRT[Btn6D])
		{

			rightTriggerD = false;

		}

		while(leftTriggerD)
		{

			motor[drive] = 127;

		}

		while(rightTriggerD)
		{

			motor[drive] = -127;

		}

		while((rightTriggerD) && (leftTriggerD) == true)
		{

			stopMotor(drive);

		}

		while((rightTriggerD) && (leftTriggerD) == false)
		{

			stopMotor(drive);

		}

	}

}
task main()
{

	while(true)// Continuously run all tasks //
	{

		startTask(armMove);
		startTask(driveMotor);

	}

}

// A Lame Robot Module

// SEASHELL_READONLY

// robot_reset() resets the robot to position 0,0 facing north with the 
//   beacon picked up
// effects: may change the robot's state
void robot_reset(void);

// robot_forward(distance) moves the robot forward by the distance or
//   outputs an error message if the distance is invalid
// effects:  may produce output
//           may change the robot's state
void robot_forward(int distance);

// robot_left() turns the robot left
// effects: changes the robot's state
void robot_left(void);

// robot_right() turns the robot right
// effects: changes the robot's state
void robot_right(void);

// robot_drop() drops the beacon at the robot's current location or
//   outputs an error message if the beacon is already placed
// effects: may produce output
//          may change the robot's state
void robot_drop(void);

// robot_pickup() picks up the beacon or outputs an error message if
//   the beacon is not at the robot's current location
// effects: may produce output
//          may change the robot's state
void robot_pickup(void);

// robot_status() prints the robot's current status
// effects: produces output
void robot_status(void);

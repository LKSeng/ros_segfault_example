# ROS SEGFAULT EXAMPLE

## Introduction

Need some ROS node that segfaults? Well, look no further (unless it doesn't work because [segfault is considered undefined behaviour, and hence by definition behaviour is not reliable](https://stackoverflow.com/questions/2045314/why-cant-i-cause-a-seg-fault). Here, attempts to segfault the ROS node would be made as part of a subscriber callback.

## Build

```shell
catkin build ros_segfault_example
```

## Usage

### Run

```shell
rosrun ros_segfault_example segfault_example_node
```

### Segfault

In another terminal, run

1. `rostopic pub /segfault_example_node/channel_0 std_msgs/String "data: 'seg'" --once` - try to segfault via SIGSEGV
2. `rostopic pub /segfault_example_node/channel_1 std_msgs/String "data: 'fault'" --once` - try to segfault by accessing out of bound memory

## Comments

Well, looks like I won't be getting hired by anyone else anytime soon lol.

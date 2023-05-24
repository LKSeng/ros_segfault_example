#include <ros/ros.h>
#include <std_msgs/String.h>

#include <signal.h> // for SIGSEGV

/*
 * @brief Callback function that raises SIGSEGV
 */
void channelCB0(const std_msgs::String::ConstPtr& msg)
{
  raise(SIGSEGV);
}

/*
 * @brief Callback function that accesses out of bound memory
 */
void channelCB1(const std_msgs::String::ConstPtr& msg)
{
  std::vector<int> v1;

  int d = 1;
  for (size_t i=0; i < 10; i++)
  {
    d = v1[i];
  }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "segfault_example_node");
    ros::NodeHandle nh("~");

    ros::Subscriber sub0 = nh.subscribe("channel_0", 1, channelCB0);
    ros::Subscriber sub1 = nh.subscribe("channel_1", 1, channelCB1);

    ros::spin();
}

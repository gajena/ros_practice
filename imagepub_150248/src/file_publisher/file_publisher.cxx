/*****************************************************************************
-----------GAJENDRA NAGAR-----------------
----------------150248--------------------
------------gajena@iitk.ac.in-------------
*****************************************************************************/

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char** argv)
{

  /*****************************************************************************
   ros node stuff : like nodehandle 
   publisher for image topic
  *****************************************************************************/
  ros::init(argc, argv, "file_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("image", 1000);
  
  while (nh.ok()) 
  {

    int freq;
    std::string file;
    //creating parameters
    nh.getParam("/file_publisher/freq",freq);
    nh.getParam("/file_publisher/file",file);
    
    ros::Rate loop_rate(freq);
    cv::Mat image = cv::imread(file, CV_LOAD_IMAGE_COLOR);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
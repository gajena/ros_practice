/*****************************************************************************
-----------GAJENDRA NAGAR-----------------
----------------150248--------------------
------------gajena@iitk.ac.in-------------
*****************************************************************************/


#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <dynamic_reconfigure/server.h>
#include <image_enhancer_150248/ImageChangerConfigConfig.h>

sensor_msgs::Image image_1;
    int brightness,contrast;

/*****************************************************************************
callback function for dynamic reconfiguration 
*****************************************************************************/
    void callback(image_enhancer_150248::ImageChangerConfigConfig &config, uint32_t level)
    {
      ROS_INFO("Reconfigure Request: %d %f ", config.brightness, config.contrast);
      brightness = config.brightness;
      contrast = config.contrast;
      return;
}
/*****************************************************************************
callback function for storing image in image_1 that will read 
subscribed from image topic
*****************************************************************************/
void imageCallback(const sensor_msgs::Image image)
{
  ROS_INFO("I heard: [%d  %d]", image.height,image.width);
  image_1=image;
  return;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_dynamic_changer");
  ros::NodeHandle nh;
  
 dynamic_reconfigure::Server<image_enhancer_150248::ImageChangerConfigConfig> server;
  dynamic_reconfigure::Server<image_enhancer_150248::ImageChangerConfigConfig>::CallbackType f;
  ros::Subscriber image_sub = nh.subscribe<sensor_msgs::Image>("image",1000,imageCallback);
  ros::Publisher cb_pub = nh.advertise<sensor_msgs::Image>("image_dynamic_changer", 1000);
  
  
  while (nh.ok()) 
  {
   

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

    ros::Rate loop_rate(20);
    
    sensor_msgs::Image a;
    a.height =image_1.height;
    a.width = image_1.width;
    a.encoding = "rgb8";
    a.step = 3*image_1.width;
    
    for(int i=0; i<(3*image_1.width*image_1.height);i=i+3)
    { 
     
          a.data.push_back(contrast*(int)image_1.data[i+2]+brightness);
          a.data.push_back(contrast*(int)image_1.data[i+1]+brightness);
          a.data.push_back(contrast*(int)image_1.data[i]+brightness);
      
    }
    if(image_1.height!=0)
    std::cout<<"****"<<contrast<<std::endl;
    cb_pub.publish(a);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
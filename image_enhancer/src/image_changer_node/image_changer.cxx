/*****************************************************************************
-----------GAJENDRA NAGAR-----------------
----------------150248--------------------
------------gajena@iitk.ac.in-------------
*****************************************************************************/

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

//global variable for image
sensor_msgs::Image image_1;

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
  /*****************************************************************************
   ros node stuff : like nodehandle subscribing to a topic,
   publisher for image changer topic
  *****************************************************************************/
  ros::init(argc, argv, "image_changer");
  ros::NodeHandle nh;
  ros::Subscriber image_sub = nh.subscribe<sensor_msgs::Image>("image",1000,imageCallback);
  ros::Publisher cb_pub = nh.advertise<sensor_msgs::Image>("image_changer", 1000);
  
  while (nh.ok()) 
  {
    // variables for params
    int brightness,contrast;
    
    // getting parametrs data
    nh.getParam("/image_changer/brightness",brightness);
    nh.getParam("/image_changer/contrast",contrast);

    ros::Rate loop_rate(20);

    // image object to be publish    
    sensor_msgs::Image a;
    a.height =image_1.height;
    a.width = image_1.width;
    a.encoding = "rgb8";
    a.step = 3*image_1.width;

    /*****************************************************************************
     giving data to image after applying modifier 
    formula I=contrast*pixel_intensity+brightness
    *****************************************************************************/
    for (int i = 0; i < (3 * image_1.width * image_1.height); i = i + 3)
    { 
     
          a.data.push_back(contrast*(int)image_1.data[i+2]+brightness);
          a.data.push_back(contrast*(int)image_1.data[i+1]+brightness);
          a.data.push_back(contrast*(int)image_1.data[i]+brightness);
      
    }
    // if(image_1.height!=0)
    // std::cout<<"****"<<contrast<<std::endl;

    //publishing modified image message 
    cb_pub.publish(a);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
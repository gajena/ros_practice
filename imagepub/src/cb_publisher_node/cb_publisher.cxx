/*****************************************************************************
-----------GAJENDRA NAGAR-----------------
----------------150248--------------------
------------gajena@iitk.ac.in-------------
*****************************************************************************/

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

int main(int argc, char** argv)
{

  /*****************************************************************************
   ros node stuff : like nodehandle 
   publisher for cb_image topic
  *****************************************************************************/
  ros::init(argc, argv, "cb_publisher");
  ros::NodeHandle nh;
  ros::Publisher cb_pub = nh.advertise<sensor_msgs::Image>("cb_img", 1000);
  
  while (nh.ok()) 
  {
    int height ,width, size,freq;
    //creating parameters
    nh.getParam("/cb_publisher/height", height);
    nh.getParam("/cb_publisher/width",width);
    nh.getParam("/cb_publisher/size",size);
    nh.getParam("/cb_publisher/freq",freq);

    ros::Rate loop_rate(freq);
    
    sensor_msgs::Image a;
    a.height =height;
    a.width = width;
    a.encoding = "rgb8";
    a.step = 3*width;

    /*****************************************************************************
     giving data to image after applying modifier 
    *****************************************************************************/

    for(int i=0; i<(width*height);i++)
    { 
      int row=i/width,col=i%width;
      if (row%(2*size)<size)
      {
        if(col%(2*size)<size)
        {
          a.data.push_back(0);
          a.data.push_back(0);
          a.data.push_back(0);
        }
        else 
        {     
          a.data.push_back(255);
          a.data.push_back(255);
          a.data.push_back(255);
        }
      }
      else 
      {
        if(col%(2*size)>=size)
        {
          a.data.push_back(0);
          a.data.push_back(0);
          a.data.push_back(0);
        }
        else 
        {     
          a.data.push_back(255);
          a.data.push_back(255);
          a.data.push_back(255);
        }
      }
    }
    cb_pub.publish(a);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
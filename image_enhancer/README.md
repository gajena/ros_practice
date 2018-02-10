# image_enhancer_150248 
# Q 1.3 & 1.4 of Assg-1 of AE640A
## 1. Nodes
### * image_changer
```
Using sensor_msgs/Image
subscribe an image topic and modify it and publish 
```
```
Parameters : 
1. image_changer/contrast (contrast of genrated image) (float type)
2. image_changer/brightness (brightness of genrated image) (integer type)
```
```
Published topic:
1. image_changer
Subscribed topic:
1. image
```
### * image_dynamic_changer
```
Using sensor_msgs/Image
Subscribe an image topic and modify it and publish
Uses dynamic reconfiguration instead of parameters
```
``` 
Dynamic reconfigure:
1. brightness (int type)
2. contrast (float type)
```
```
Published topic:
1. image_dynamic_changer
Subscribed topic:
1. image
```
## 2. launch 
### * image_changer.launch
``` 
# it contains image_changer node with default parameter 
```
### * file_publisher.launch
```
# it contains file_publisher node with default parameter
```
## 3. param
``` 
# contains param file 
1. image_changer.yaml
```
## 4. How to launch
```shell
roslanch image_enhancer_150248 image_changer.launch
```
```shell
rosrun image_enhancer_150248 image_dynamic_changer
```
## 5. Acces parameters
```shell
# to get parameter list
rosparam list
```

# Imagepub_150248 
# Q 1.1 & 1.2 of Assg-1 of AE640A
## 1. Nodes
### * cb_publisher
```
Using sensor_msgs/Image
genrates a checkerboard image
```
```
Parameters : 
1. cb_publisher/height (height of genrated image)(integer type)
2. cb_publisher/width (width of genrated image) (integer type)
3. cb_publisher/size (side of genrated square of checkerboard) (integer type)
4. cb_publisher/freq (rate of publishing image) (integer type)
```
```
Published topic:
1. cb_img
```
### * file_publisher
```
Using OpenCV, cv_bridge
read image from disk
```
``` 
Parameters : 
1. file_publisher/file (path to image)(string type)
2. file_publisher/freq (rate of publishing image) (integer type)
```
```
Published topic:
1. image
```
## 2. launch 
### * cb_publisher.launch
``` 
# it contains cb_publisher node with default parameter 
```
### * file_publisher.launch
```
# it contains file_publisher node with default parameter
```
## 3. param
``` 
# contains two param file 
1. cb_publisher.yaml
2. file_publisher.yaml
```
## 4. How to launch
```shell
roslanch imagepub_150248 cb_publisher.launch
```
## 5. Acces parameters
```shell
# to get parameter list
rosparam list
```
```shell
# to set/get parameters 
rosparam set /file_publisher/file 'path to file' 
```

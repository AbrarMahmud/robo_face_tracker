# Robotic Face Tracker using ROS 🤖👁️

![ROS Noetic](https://img.shields.io/badge/ROS-Noetic-green)
![Python 3](https://img.shields.io/badge/Python-3-blue)
![YOLOv5](https://img.shields.io/badge/YOLO-v5-orange)

A modular ROS 1 (Noetic) project for robotic face/object tracking. The system captures a live webcam feed, runs real-time object detection using YOLOv5, and translates the detected bounding boxes into 3D neck movements. The robotic neck movements are speed-interpolated to ensure smooth, natural motion.

![Project Demo](src/proj.gif)

## 🌟 Features

* **Webcam Publishing**: Efficiently captures and publishes live video feeds to ROS topics.
* **YOLOv5 Integration**: High-speed, real-time bounding box detection using a custom YOLOv5 ROS wrapper.
* **Custom ROS Messages**: Utilizes bespoke `.msg` files for clean and organized bounding box data transmission.
* **Natural Movement**: Translates 2D bounding boxes into 3D robotic neck movements, utilizing speed interpolation for lifelike, smooth tracking.

## 📁 Repository Structure

The workspace consists of three main ROS packages:

* `cv_basics`: Contains the `webcam_pub.py` node that interfaces with the camera and publishes image frames.
* `detection_msgs`: Contains custom ROS message definitions (`BoundingBox.msg` and `BoundingBoxes.msg`) for communication between nodes.
* `yolov5_ros`: The core detection package containing the YOLOv5 neural network, launch files, and the `detect.py` node that processes images and outputs bounding boxes.

## 🛠️ Prerequisites

* **OS**: Ubuntu 20.04
* **ROS**: ROS 1 Noetic
* **Python**: Python 3.8+
* **Dependencies**: 
  * `PyTorch` and `torchvision`
  * `OpenCV` (`cv2`)
  * `cv_bridge`, `rospy`, `sensor_msgs`, `std_msgs`

You can install the Python requirements for YOLOv5 via:
```bash
cd src/yolov5_ros/src/yolov5
pip3 install -r requirements.txt# robo_face_tracker

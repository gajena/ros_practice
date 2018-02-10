add_executable (file_publisher file_publisher.cxx)
target_link_libraries (file_publisher
						${catkin_LIBRARIES}
						${OpenCV_LIBRARIES}
)

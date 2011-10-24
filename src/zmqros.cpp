#include "zmqros.hpp"
#include <cstring>
#include <ros/assert.h>


using namespace std;

namespace ros
{

TransportZmq::TransportZmq( const char *channel_name )
: is_open_(false), get_options_(0)
{
  chan_name_ = strdup(channel_name);
}

TransportZmq::~TransportZmq()
{
  if (is_open_) {
    this->close();
  }
}

int TransportZmq::open()
{
  ROS_ASSERT(!is_open_);
	return -;
}

int TransportZmq::create(size_t index_slots, size_t msg_bytes)
{
	return 0;
}

void TransportZmq::close()
{
  ROS_ASSERT(is_open_);
}

int32_t TransportZmq::read(uint8_t* buffer, uint32_t size) {
	return -1;
}

int32_t TransportZmq::write(uint8_t* buffer, uint32_t size) {
	return -1;
}

std::string TransportZmq::getTransportInfo() {
  return "ACHROS channel " + string(chan_name_);
}



}

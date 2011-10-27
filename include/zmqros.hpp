#ifndef ZMQROS_HPP
#define ZMQROS_HPP

/** \file zmqros.cpp
 */

#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <ros/types.h>
#include <ros/transport/transport.h>

namespace ros
{

class TransportZmq;
typedef boost::shared_ptr<TransportZmq> TransportZmqPtr;

/**
 * \brief ZMQROS transport
 */
class /*ROSCPP_DECL*/ TransportZmq /*: public Transport*/
{
public:
  TransportZmq( const char *channel_name );
  virtual ~TransportZmq();

  /** \brief Create the channel */
  int create(size_t index_slots=16, size_t msg_bytes=8192);
  /** \brief Open the channel */
  int open();
  /** \brief Option flags for ach_get */
  void setGetOptions( int opts ) { get_options_ = opts; }

  // overrides from Transport
  virtual int32_t read(uint8_t* buffer, uint32_t size);
  virtual int32_t write(uint8_t* buffer, uint32_t size);

  // these don't mean anything to Ach
  virtual void enableWrite() {}
  virtual void disableWrite() {}
  virtual void enableRead() {}
  virtual void disableRead() {}

  virtual void close();

  virtual std::string getTransportInfo();

  virtual void parseHeader(const Header& header);

  virtual const char* getType() { return "ACHROS"; }

protected:
  ach_channel_t chan_;
  const char *chan_name_;
  bool is_open_;
  int get_options_;
};


}


#endif //ACHROS_HPP

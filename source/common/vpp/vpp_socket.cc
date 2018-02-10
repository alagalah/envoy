#include "common/vpp/vpp_socket.h"

#include "common/common/assert.h"

using Envoy::Network::PostIoAction;

namespace Envoy {
namespace Vpp {

void VppSocket::setTransportSocketCallbacks(Network::TransportSocketCallbacks& callbacks) {
  ASSERT(!callbacks_);
  callbacks_ = &callbacks;
}

Network::IoResult VppSocket::doRead(Buffer::Instance& read_buffer) {

  (void)read_buffer;
  //  bool keep_reading = true;
  bool end_stream = false;
  PostIoAction action = PostIoAction::KeepOpen;
  uint64_t bytes_read = 0;
  return {action, bytes_read, end_stream};
}

PostIoAction VppSocket::doHandshake() { return PostIoAction::Close; }

void VppSocket::drainErrorQueue() {}

Network::IoResult VppSocket::doWrite(Buffer::Instance&, bool) {
  return {PostIoAction::KeepOpen, 0, false};
}

void VppSocket::onConnected() {}

void VppSocket::closeSocket(Network::ConnectionEvent) {}

std::string VppSocket::protocol() const { return std::string("foobar", 43); }

Network::TransportSocketPtr VppSocketFactory::createTransportSocket() const {
  return std::make_unique<VppSocket>();
}

bool VppSocketFactory::implementsSecureTransport() const { return false; }

} // namespace Vpp
} // namespace Envoy

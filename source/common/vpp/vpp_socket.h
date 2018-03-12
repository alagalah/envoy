#pragma once

#include <cstdint>
#include <string>

#include "envoy/network/transport_socket.h"

#include "common/common/logger.h"

namespace Envoy {
namespace Vpp {

enum class InitialState { Client, Server };

class VppSocket : public Network::TransportSocket,
                  protected Logger::Loggable<Logger::Id::connection> {
public:
  // Network::TransportSocket
  void setTransportSocketCallbacks(Network::TransportSocketCallbacks& callbacks) override;
  std::string protocol() const override;
  bool canFlushClose() override { return true; }
  void closeSocket(Network::ConnectionEvent close_type) override;
  Network::IoResult doRead(Buffer::Instance& read_buffer) override;
  Network::IoResult doWrite(Buffer::Instance& write_buffer, bool end_stream) override;
  void onConnected() override;
  Ssl::Connection* ssl() override { return nullptr; }
  const Ssl::Connection* ssl() const override { return nullptr; }

private:
  Network::PostIoAction doHandshake();
  void drainErrorQueue();
  void shutdownVpp();

  Network::TransportSocketCallbacks* callbacks_{};
  // Maybe this is where I put reference to singleton VPPAPI connection?  bssl::UniquePtr<SSL> ssl_;
};

class VppSocketFactory : public Network::TransportSocketFactory {
public:
  // Network::TransportSocketFactory
  Network::TransportSocketPtr createTransportSocket() const override;

  bool implementsSecureTransport() const override;
};

} // namespace Vpp
} // namespace Envoy

#include "server/config/network/vpp_socket.h"

#include "envoy/registry/registry.h"

#include "common/vpp/vpp_socket.h"

namespace Envoy {
namespace Server {
namespace Configuration {

Network::TransportSocketFactoryPtr
UpstreamVppSocketFactory::createTransportSocketFactory(const Protobuf::Message&,
                                                       TransportSocketFactoryContext&) {
  return std::make_unique<Vpp::VppSocketFactory>();
}

Network::TransportSocketFactoryPtr DownstreamVppSocketFactory::createTransportSocketFactory(
    const std::string&, const std::vector<std::string>&, bool, const Protobuf::Message&,
    TransportSocketFactoryContext&) {
  return std::make_unique<Vpp::VppSocketFactory>();
}

ProtobufTypes::MessagePtr VppSocketFactory::createEmptyConfigProto() {
  return std::make_unique<ProtobufWkt::Empty>();
}

static Registry::RegisterFactory<UpstreamVppSocketFactory, UpstreamTransportSocketConfigFactory>
    upstream_registered_;

static Registry::RegisterFactory<DownstreamVppSocketFactory, DownstreamTransportSocketConfigFactory>
    downstream_registered_;

} // namespace Configuration
} // namespace Server
} // namespace Envoy

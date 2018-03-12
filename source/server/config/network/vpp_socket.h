#pragma once

#include "envoy/server/transport_socket_config.h"

#include "common/config/well_known_names.h"

namespace Envoy {
namespace Server {
namespace Configuration {

/**
 * Config registration for the VPP transport socket factory.
 * @see TransportSocketConfigFactory.
 */
class VppSocketFactory : public virtual TransportSocketConfigFactory {
public:
  virtual ~VppSocketFactory() {}
  std::string name() const override { return Config::TransportSocketNames::get().VPP; }
  ProtobufTypes::MessagePtr createEmptyConfigProto() override;
};

class UpstreamVppSocketFactory : public UpstreamTransportSocketConfigFactory,
                                 public VppSocketFactory {
public:
  Network::TransportSocketFactoryPtr
  createTransportSocketFactory(const Protobuf::Message& config,
                               TransportSocketFactoryContext& context) override;
};

class DownstreamVppSocketFactory : public DownstreamTransportSocketConfigFactory,
                                   public VppSocketFactory {
public:
  Network::TransportSocketFactoryPtr
  createTransportSocketFactory(const std::string& listener_name,
                               const std::vector<std::string>& server_names,
                               bool skip_context_update, const Protobuf::Message& config,
                               TransportSocketFactoryContext& context) override;
};

} // namespace Configuration
} // namespace Server
} // namespace Envoy

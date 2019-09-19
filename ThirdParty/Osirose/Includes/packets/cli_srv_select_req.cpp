#include "cli_srv_select_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSrvSelectReq::CliSrvSelectReq() : CRosePacket(CliSrvSelectReq::PACKET_ID) {}

CliSrvSelectReq::CliSrvSelectReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(serverId)) {
        return;
    }
    if (!reader.get_uint8_t(channelId)) {
        return;
    }
}

CliSrvSelectReq& CliSrvSelectReq::set_serverId(const uint32_t serverId) {
    this->serverId = serverId;
    return *this;
}

uint32_t CliSrvSelectReq::get_serverId() const {
    return serverId;
}

CliSrvSelectReq& CliSrvSelectReq::set_channelId(const uint8_t channelId) {
    this->channelId = channelId;
    return *this;
}

uint8_t CliSrvSelectReq::get_channelId() const {
    return channelId;
}

CliSrvSelectReq CliSrvSelectReq::create(const uint32_t& serverId, const uint8_t& channelId) {
    CliSrvSelectReq packet;
    packet.set_serverId(serverId);
    packet.set_channelId(channelId);
    return packet;
}

CliSrvSelectReq CliSrvSelectReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSrvSelectReq(reader);
}

std::unique_ptr<CliSrvSelectReq> CliSrvSelectReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSrvSelectReq>(reader);
}

bool CliSrvSelectReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(serverId)) {
        return false;
    }
    if (!writer.set_uint8_t(channelId)) {
        return false;
    }
    return true;
}

constexpr size_t CliSrvSelectReq::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // serverId
    size += sizeof(uint8_t); // channelId
    return size;
}


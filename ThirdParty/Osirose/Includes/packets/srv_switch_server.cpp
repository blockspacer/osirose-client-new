#include "srv_switch_server.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSwitchServer::SrvSwitchServer() : CRosePacket(SrvSwitchServer::PACKET_ID) {}

SrvSwitchServer::SrvSwitchServer(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(port)) {
        return;
    }
    if (!reader.get_uint32_t(sessionId)) {
        return;
    }
    if (!reader.get_uint32_t(sessionSeed)) {
        return;
    }
    if (!reader.get_string(ip)) {
        return;
    }
}

SrvSwitchServer& SrvSwitchServer::set_port(const uint16_t port) {
    this->port = port;
    return *this;
}

uint16_t SrvSwitchServer::get_port() const {
    return port;
}

SrvSwitchServer& SrvSwitchServer::set_sessionId(const uint32_t sessionId) {
    this->sessionId = sessionId;
    return *this;
}

uint32_t SrvSwitchServer::get_sessionId() const {
    return sessionId;
}

SrvSwitchServer& SrvSwitchServer::set_sessionSeed(const uint32_t sessionSeed) {
    this->sessionSeed = sessionSeed;
    return *this;
}

uint32_t SrvSwitchServer::get_sessionSeed() const {
    return sessionSeed;
}

SrvSwitchServer& SrvSwitchServer::set_ip(const std::string& ip) {
    this->ip = ip;
    return *this;
}

const std::string& SrvSwitchServer::get_ip() const {
    return ip;
}

SrvSwitchServer SrvSwitchServer::create(const uint16_t& port, const uint32_t& sessionId, const uint32_t& sessionSeed, const std::string& ip) {
    SrvSwitchServer packet;
    packet.set_port(port);
    packet.set_sessionId(sessionId);
    packet.set_sessionSeed(sessionSeed);
    packet.set_ip(ip);
    return packet;
}

SrvSwitchServer SrvSwitchServer::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSwitchServer(reader);
}

std::unique_ptr<SrvSwitchServer> SrvSwitchServer::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSwitchServer>(reader);
}

bool SrvSwitchServer::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(port)) {
        return false;
    }
    if (!writer.set_uint32_t(sessionId)) {
        return false;
    }
    if (!writer.set_uint32_t(sessionSeed)) {
        return false;
    }
    if (!writer.set_string(ip)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSwitchServer::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // port
    size += sizeof(uint32_t); // sessionId
    size += sizeof(uint32_t); // sessionSeed
    return size;
}


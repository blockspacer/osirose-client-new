#include "srv_srv_select_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSrvSelectReply::SrvSrvSelectReply() : CRosePacket(SrvSrvSelectReply::PACKET_ID) {}

SrvSrvSelectReply::SrvSrvSelectReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint32_t(sessionId)) {
        return;
    }
    if (!reader.get_uint32_t(cryptVal)) {
        return;
    }
    if (!reader.get_string(ip)) {
        return;
    }
    if (!reader.get_uint16_t(port)) {
        return;
    }
}

SrvSrvSelectReply& SrvSrvSelectReply::set_result(const SrvSrvSelectReply::Result result) {
    this->result = result;
    return *this;
}

SrvSrvSelectReply::Result SrvSrvSelectReply::get_result() const {
    return result;
}

SrvSrvSelectReply& SrvSrvSelectReply::set_sessionId(const uint32_t sessionId) {
    this->sessionId = sessionId;
    return *this;
}

uint32_t SrvSrvSelectReply::get_sessionId() const {
    return sessionId;
}

SrvSrvSelectReply& SrvSrvSelectReply::set_cryptVal(const uint32_t cryptVal) {
    this->cryptVal = cryptVal;
    return *this;
}

uint32_t SrvSrvSelectReply::get_cryptVal() const {
    return cryptVal;
}

SrvSrvSelectReply& SrvSrvSelectReply::set_ip(const std::string& ip) {
    this->ip = ip;
    return *this;
}

const std::string& SrvSrvSelectReply::get_ip() const {
    return ip;
}

SrvSrvSelectReply& SrvSrvSelectReply::set_port(const uint16_t port) {
    this->port = port;
    return *this;
}

uint16_t SrvSrvSelectReply::get_port() const {
    return port;
}

SrvSrvSelectReply SrvSrvSelectReply::create(const SrvSrvSelectReply::Result& result, const uint32_t& sessionId, const uint32_t& cryptVal, const std::string& ip, const uint16_t& port) {
    SrvSrvSelectReply packet;
    packet.set_result(result);
    packet.set_sessionId(sessionId);
    packet.set_cryptVal(cryptVal);
    packet.set_ip(ip);
    packet.set_port(port);
    return packet;
}

SrvSrvSelectReply SrvSrvSelectReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSrvSelectReply(reader);
}

std::unique_ptr<SrvSrvSelectReply> SrvSrvSelectReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSrvSelectReply>(reader);
}

bool SrvSrvSelectReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint32_t(sessionId)) {
        return false;
    }
    if (!writer.set_uint32_t(cryptVal)) {
        return false;
    }
    if (!writer.set_string(ip)) {
        return false;
    }
    if (!writer.set_uint16_t(port)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSrvSelectReply::size() {
    size_t size = 0;
    size += sizeof(Result); // result
    size += sizeof(uint32_t); // sessionId
    size += sizeof(uint32_t); // cryptVal
    size += sizeof(uint16_t); // port
    return size;
}


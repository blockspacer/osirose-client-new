#include "cli_select_char_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSelectCharReq::CliSelectCharReq() : CRosePacket(CliSelectCharReq::PACKET_ID) {}

CliSelectCharReq::CliSelectCharReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(charId)) {
        return;
    }
    if (!reader.get_uint8_t(runMode)) {
        return;
    }
    if (!reader.get_uint8_t(rideMode)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

CliSelectCharReq& CliSelectCharReq::set_charId(const uint8_t charId) {
    this->charId = charId;
    return *this;
}

uint8_t CliSelectCharReq::get_charId() const {
    return charId;
}

CliSelectCharReq& CliSelectCharReq::set_runMode(const uint8_t runMode) {
    this->runMode = runMode;
    return *this;
}

uint8_t CliSelectCharReq::get_runMode() const {
    return runMode;
}

CliSelectCharReq& CliSelectCharReq::set_rideMode(const uint8_t rideMode) {
    this->rideMode = rideMode;
    return *this;
}

uint8_t CliSelectCharReq::get_rideMode() const {
    return rideMode;
}

CliSelectCharReq& CliSelectCharReq::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& CliSelectCharReq::get_name() const {
    return name;
}

CliSelectCharReq CliSelectCharReq::create(const uint8_t& charId, const uint8_t& runMode, const uint8_t& rideMode, const std::string& name) {
    CliSelectCharReq packet;
    packet.set_charId(charId);
    packet.set_runMode(runMode);
    packet.set_rideMode(rideMode);
    packet.set_name(name);
    return packet;
}

CliSelectCharReq CliSelectCharReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSelectCharReq(reader);
}

std::unique_ptr<CliSelectCharReq> CliSelectCharReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSelectCharReq>(reader);
}

bool CliSelectCharReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(charId)) {
        return false;
    }
    if (!writer.set_uint8_t(runMode)) {
        return false;
    }
    if (!writer.set_uint8_t(rideMode)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t CliSelectCharReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // charId
    size += sizeof(uint8_t); // runMode
    size += sizeof(uint8_t); // rideMode
    return size;
}


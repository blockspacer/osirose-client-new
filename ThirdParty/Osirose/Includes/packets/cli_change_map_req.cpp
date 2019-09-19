#include "cli_change_map_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliChangeMapReq::CliChangeMapReq() : CRosePacket(CliChangeMapReq::PACKET_ID) {}

CliChangeMapReq::CliChangeMapReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(weightRate)) {
        return;
    }
    if (!reader.get_uint16_t(z)) {
        return;
    }
}

CliChangeMapReq& CliChangeMapReq::set_weightRate(const uint8_t weightRate) {
    this->weightRate = weightRate;
    return *this;
}

uint8_t CliChangeMapReq::get_weightRate() const {
    return weightRate;
}

CliChangeMapReq& CliChangeMapReq::set_z(const uint16_t z) {
    this->z = z;
    return *this;
}

uint16_t CliChangeMapReq::get_z() const {
    return z;
}

CliChangeMapReq CliChangeMapReq::create(const uint8_t& weightRate, const uint16_t& z) {
    CliChangeMapReq packet;
    packet.set_weightRate(weightRate);
    packet.set_z(z);
    return packet;
}

CliChangeMapReq CliChangeMapReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliChangeMapReq(reader);
}

std::unique_ptr<CliChangeMapReq> CliChangeMapReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliChangeMapReq>(reader);
}

bool CliChangeMapReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(weightRate)) {
        return false;
    }
    if (!writer.set_uint16_t(z)) {
        return false;
    }
    return true;
}

constexpr size_t CliChangeMapReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // weightRate
    size += sizeof(uint16_t); // z
    return size;
}


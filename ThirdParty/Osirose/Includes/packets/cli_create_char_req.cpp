#include "cli_create_char_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliCreateCharReq::CliCreateCharReq() : CRosePacket(CliCreateCharReq::PACKET_ID) {}

CliCreateCharReq::CliCreateCharReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(race)) {
        return;
    }
    if (!reader.get_uint8_t(stone)) {
        return;
    }
    if (!reader.get_uint8_t(hair)) {
        return;
    }
    if (!reader.get_uint8_t(face)) {
        return;
    }
    if (!reader.get_uint8_t(weapon)) {
        return;
    }
    if (!reader.get_uint16_t(zone)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

CliCreateCharReq& CliCreateCharReq::set_race(const uint8_t race) {
    this->race = race;
    return *this;
}

uint8_t CliCreateCharReq::get_race() const {
    return race;
}

CliCreateCharReq& CliCreateCharReq::set_stone(const uint8_t stone) {
    this->stone = stone;
    return *this;
}

uint8_t CliCreateCharReq::get_stone() const {
    return stone;
}

CliCreateCharReq& CliCreateCharReq::set_hair(const uint8_t hair) {
    this->hair = hair;
    return *this;
}

uint8_t CliCreateCharReq::get_hair() const {
    return hair;
}

CliCreateCharReq& CliCreateCharReq::set_face(const uint8_t face) {
    this->face = face;
    return *this;
}

uint8_t CliCreateCharReq::get_face() const {
    return face;
}

CliCreateCharReq& CliCreateCharReq::set_weapon(const uint8_t weapon) {
    this->weapon = weapon;
    return *this;
}

uint8_t CliCreateCharReq::get_weapon() const {
    return weapon;
}

CliCreateCharReq& CliCreateCharReq::set_zone(const uint16_t zone) {
    this->zone = zone;
    return *this;
}

uint16_t CliCreateCharReq::get_zone() const {
    return zone;
}

CliCreateCharReq& CliCreateCharReq::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& CliCreateCharReq::get_name() const {
    return name;
}

CliCreateCharReq CliCreateCharReq::create(const uint8_t& race, const uint8_t& stone, const uint8_t& hair, const uint8_t& face, const uint8_t& weapon, const uint16_t& zone, const std::string& name) {
    CliCreateCharReq packet;
    packet.set_race(race);
    packet.set_stone(stone);
    packet.set_hair(hair);
    packet.set_face(face);
    packet.set_weapon(weapon);
    packet.set_zone(zone);
    packet.set_name(name);
    return packet;
}

CliCreateCharReq CliCreateCharReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliCreateCharReq(reader);
}

std::unique_ptr<CliCreateCharReq> CliCreateCharReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliCreateCharReq>(reader);
}

bool CliCreateCharReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(race)) {
        return false;
    }
    if (!writer.set_uint8_t(stone)) {
        return false;
    }
    if (!writer.set_uint8_t(hair)) {
        return false;
    }
    if (!writer.set_uint8_t(face)) {
        return false;
    }
    if (!writer.set_uint8_t(weapon)) {
        return false;
    }
    if (!writer.set_uint16_t(zone)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t CliCreateCharReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // race
    size += sizeof(uint8_t); // stone
    size += sizeof(uint8_t); // hair
    size += sizeof(uint8_t); // face
    size += sizeof(uint8_t); // weapon
    size += sizeof(uint16_t); // zone
    return size;
}


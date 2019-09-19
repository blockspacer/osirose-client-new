#include "cli_delete_char_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliDeleteCharReq::CliDeleteCharReq() : CRosePacket(CliDeleteCharReq::PACKET_ID) {}

CliDeleteCharReq::CliDeleteCharReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(charId)) {
        return;
    }
    if (!reader.get_uint8_t(isDelete)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

CliDeleteCharReq& CliDeleteCharReq::set_charId(const uint8_t charId) {
    this->charId = charId;
    return *this;
}

uint8_t CliDeleteCharReq::get_charId() const {
    return charId;
}

CliDeleteCharReq& CliDeleteCharReq::set_isDelete(const uint8_t isDelete) {
    this->isDelete = isDelete;
    return *this;
}

uint8_t CliDeleteCharReq::get_isDelete() const {
    return isDelete;
}

CliDeleteCharReq& CliDeleteCharReq::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& CliDeleteCharReq::get_name() const {
    return name;
}

CliDeleteCharReq CliDeleteCharReq::create(const uint8_t& charId, const uint8_t& isDelete, const std::string& name) {
    CliDeleteCharReq packet;
    packet.set_charId(charId);
    packet.set_isDelete(isDelete);
    packet.set_name(name);
    return packet;
}

CliDeleteCharReq CliDeleteCharReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliDeleteCharReq(reader);
}

std::unique_ptr<CliDeleteCharReq> CliDeleteCharReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliDeleteCharReq>(reader);
}

bool CliDeleteCharReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(charId)) {
        return false;
    }
    if (!writer.set_uint8_t(isDelete)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t CliDeleteCharReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // charId
    size += sizeof(uint8_t); // isDelete
    return size;
}


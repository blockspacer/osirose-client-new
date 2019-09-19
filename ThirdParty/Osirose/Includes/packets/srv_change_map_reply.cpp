#include "srv_change_map_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvChangeMapReply::SrvChangeMapReply() : CRosePacket(SrvChangeMapReply::PACKET_ID) {}

SrvChangeMapReply::SrvChangeMapReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(objectIndex)) {
        return;
    }
    if (!reader.get_uint16_t(hp)) {
        return;
    }
    if (!reader.get_uint16_t(mp)) {
        return;
    }
    if (!reader.get_uint16_t(xp)) {
        return;
    }
    if (!reader.get_uint16_t(penalizeXp)) {
        return;
    }
    if (!reader.get_uint16_t(craftRate)) {
        return;
    }
    if (!reader.get_uint16_t(updateTime)) {
        return;
    }
    if (!reader.get_uint16_t(worldRate)) {
        return;
    }
    if (!reader.get_uint8_t(townRate)) {
        return;
    }
    for (size_t index = 0; index < MAX_SELL_TYPE; ++index) {
        if (!reader.get_uint8_t(itemRate[index])) {
            return;
        }
    }
    if (!reader.get_uint32_t(flags)) {
        return;
    }
    if (!reader.get_uint16_t(worldTime)) {
        return;
    }
    if (!reader.get_uint16_t(teamNumber)) {
        return;
    }
}

SrvChangeMapReply& SrvChangeMapReply::set_objectIndex(const uint16_t objectIndex) {
    this->objectIndex = objectIndex;
    return *this;
}

uint16_t SrvChangeMapReply::get_objectIndex() const {
    return objectIndex;
}

SrvChangeMapReply& SrvChangeMapReply::set_hp(const uint16_t hp) {
    this->hp = hp;
    return *this;
}

uint16_t SrvChangeMapReply::get_hp() const {
    return hp;
}

SrvChangeMapReply& SrvChangeMapReply::set_mp(const uint16_t mp) {
    this->mp = mp;
    return *this;
}

uint16_t SrvChangeMapReply::get_mp() const {
    return mp;
}

SrvChangeMapReply& SrvChangeMapReply::set_xp(const uint16_t xp) {
    this->xp = xp;
    return *this;
}

uint16_t SrvChangeMapReply::get_xp() const {
    return xp;
}

SrvChangeMapReply& SrvChangeMapReply::set_penalizeXp(const uint16_t penalizeXp) {
    this->penalizeXp = penalizeXp;
    return *this;
}

uint16_t SrvChangeMapReply::get_penalizeXp() const {
    return penalizeXp;
}

SrvChangeMapReply& SrvChangeMapReply::set_craftRate(const uint16_t craftRate) {
    this->craftRate = craftRate;
    return *this;
}

uint16_t SrvChangeMapReply::get_craftRate() const {
    return craftRate;
}

SrvChangeMapReply& SrvChangeMapReply::set_updateTime(const uint16_t updateTime) {
    this->updateTime = updateTime;
    return *this;
}

uint16_t SrvChangeMapReply::get_updateTime() const {
    return updateTime;
}

SrvChangeMapReply& SrvChangeMapReply::set_worldRate(const uint16_t worldRate) {
    this->worldRate = worldRate;
    return *this;
}

uint16_t SrvChangeMapReply::get_worldRate() const {
    return worldRate;
}

SrvChangeMapReply& SrvChangeMapReply::set_townRate(const uint8_t townRate) {
    this->townRate = townRate;
    return *this;
}

uint8_t SrvChangeMapReply::get_townRate() const {
    return townRate;
}

SrvChangeMapReply& SrvChangeMapReply::set_itemRate(const std::array<uint8_t, MAX_SELL_TYPE> itemRate) {
    this->itemRate = itemRate;
    return *this;
}

SrvChangeMapReply& SrvChangeMapReply::set_itemRate(const uint8_t itemRate, size_t index) {
    this->itemRate[index] = itemRate;
    return *this;
}

std::array<uint8_t, MAX_SELL_TYPE> SrvChangeMapReply::get_itemRate() const {
    return itemRate;
}

uint8_t SrvChangeMapReply::get_itemRate(size_t index) const {
    return itemRate[index];
}

SrvChangeMapReply& SrvChangeMapReply::set_flags(const uint32_t flags) {
    this->flags = flags;
    return *this;
}

uint32_t SrvChangeMapReply::get_flags() const {
    return flags;
}

SrvChangeMapReply& SrvChangeMapReply::set_worldTime(const uint16_t worldTime) {
    this->worldTime = worldTime;
    return *this;
}

uint16_t SrvChangeMapReply::get_worldTime() const {
    return worldTime;
}

SrvChangeMapReply& SrvChangeMapReply::set_teamNumber(const uint16_t teamNumber) {
    this->teamNumber = teamNumber;
    return *this;
}

uint16_t SrvChangeMapReply::get_teamNumber() const {
    return teamNumber;
}

SrvChangeMapReply SrvChangeMapReply::create(const uint16_t& objectIndex, const uint16_t& hp, const uint16_t& mp, const uint16_t& xp, const uint16_t& penalizeXp, const uint16_t& worldTime, const uint16_t& teamNumber) {
    SrvChangeMapReply packet;
    packet.set_objectIndex(objectIndex);
    packet.set_hp(hp);
    packet.set_mp(mp);
    packet.set_xp(xp);
    packet.set_penalizeXp(penalizeXp);
    packet.set_worldTime(worldTime);
    packet.set_teamNumber(teamNumber);
    return packet;
}

SrvChangeMapReply SrvChangeMapReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChangeMapReply(reader);
}

std::unique_ptr<SrvChangeMapReply> SrvChangeMapReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChangeMapReply>(reader);
}

bool SrvChangeMapReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(objectIndex)) {
        return false;
    }
    if (!writer.set_uint16_t(hp)) {
        return false;
    }
    if (!writer.set_uint16_t(mp)) {
        return false;
    }
    if (!writer.set_uint16_t(xp)) {
        return false;
    }
    if (!writer.set_uint16_t(penalizeXp)) {
        return false;
    }
    if (!writer.set_uint16_t(craftRate)) {
        return false;
    }
    if (!writer.set_uint16_t(updateTime)) {
        return false;
    }
    if (!writer.set_uint16_t(worldRate)) {
        return false;
    }
    if (!writer.set_uint8_t(townRate)) {
        return false;
    }
    for (const auto& elem : itemRate) {
        if (!writer.set_uint8_t(elem)) {
            return false;
        }
    }
    if (!writer.set_uint32_t(flags)) {
        return false;
    }
    if (!writer.set_uint16_t(worldTime)) {
        return false;
    }
    if (!writer.set_uint16_t(teamNumber)) {
        return false;
    }
    return true;
}

constexpr size_t SrvChangeMapReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // objectIndex
    size += sizeof(uint16_t); // hp
    size += sizeof(uint16_t); // mp
    size += sizeof(uint16_t); // xp
    size += sizeof(uint16_t); // penalizeXp
    size += sizeof(uint16_t); // craftRate
    size += sizeof(uint16_t); // updateTime
    size += sizeof(uint16_t); // worldRate
    size += sizeof(uint8_t); // townRate
    size += sizeof(uint8_t) * MAX_SELL_TYPE; // itemRate
    size += sizeof(uint32_t); // flags
    size += sizeof(uint16_t); // worldTime
    size += sizeof(uint16_t); // teamNumber
    return size;
}


#include "srv_channel_list_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvChannelListReply::ChannelInfo& SrvChannelListReply::ChannelInfo::set_id(const uint8_t id) {
    this->id = id;
    return *this;
}

uint8_t SrvChannelListReply::ChannelInfo::get_id() const {
    return id;
}

SrvChannelListReply::ChannelInfo& SrvChannelListReply::ChannelInfo::set_lowAge(const uint8_t lowAge) {
    this->lowAge = lowAge;
    return *this;
}

uint8_t SrvChannelListReply::ChannelInfo::get_lowAge() const {
    return lowAge;
}

SrvChannelListReply::ChannelInfo& SrvChannelListReply::ChannelInfo::set_highAge(const uint8_t highAge) {
    this->highAge = highAge;
    return *this;
}

uint8_t SrvChannelListReply::ChannelInfo::get_highAge() const {
    return highAge;
}

SrvChannelListReply::ChannelInfo& SrvChannelListReply::ChannelInfo::set_capacity(const uint16_t capacity) {
    this->capacity = capacity;
    return *this;
}

uint16_t SrvChannelListReply::ChannelInfo::get_capacity() const {
    return capacity;
}

SrvChannelListReply::ChannelInfo& SrvChannelListReply::ChannelInfo::set_name(const std::string name) {
    this->name = name;
    return *this;
}

std::string SrvChannelListReply::ChannelInfo::get_name() const {
    return name;
}

bool SrvChannelListReply::ChannelInfo::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(lowAge)) {
        return false;
    }
    if (!writer.set_uint8_t(highAge)) {
        return false;
    }
    if (!writer.set_uint16_t(capacity)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

bool SrvChannelListReply::ChannelInfo::read(CRoseReader& reader) {
    if (!reader.get_uint8_t(id)) {
        return false;
    }
    if (!reader.get_uint8_t(lowAge)) {
        return false;
    }
    if (!reader.get_uint8_t(highAge)) {
        return false;
    }
    if (!reader.get_uint16_t(capacity)) {
        return false;
    }
    if (!reader.get_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t SrvChannelListReply::ChannelInfo::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // id
    size += sizeof(uint8_t); // lowAge
    size += sizeof(uint8_t); // highAge
    size += sizeof(uint16_t); // capacity
    return size;
}


SrvChannelListReply::SrvChannelListReply() : CRosePacket(SrvChannelListReply::PACKET_ID) {}

SrvChannelListReply::SrvChannelListReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(id)) {
        return;
    }
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            SrvChannelListReply::ChannelInfo elem;
            if (!reader.get_iserialize(elem)) {
                return;
            }
            channels.push_back(elem);
        }
    }
}

SrvChannelListReply& SrvChannelListReply::set_id(const uint32_t id) {
    this->id = id;
    return *this;
}

uint32_t SrvChannelListReply::get_id() const {
    return id;
}

SrvChannelListReply& SrvChannelListReply::set_channels(const std::vector<SrvChannelListReply::ChannelInfo> channels) {
    this->channels = channels;
    return *this;
}

SrvChannelListReply& SrvChannelListReply::add_channels(const ChannelInfo channels) {
    this->channels.emplace_back(channels);
    return *this;
}

std::vector<SrvChannelListReply::ChannelInfo> SrvChannelListReply::get_channels() const {
    return channels;
}

SrvChannelListReply::ChannelInfo SrvChannelListReply::get_channels(size_t index) const {
    return channels[index];
}

SrvChannelListReply SrvChannelListReply::create(const uint32_t& id) {
    SrvChannelListReply packet;
    packet.set_id(id);
    return packet;
}

SrvChannelListReply SrvChannelListReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChannelListReply(reader);
}

std::unique_ptr<SrvChannelListReply> SrvChannelListReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChannelListReply>(reader);
}

bool SrvChannelListReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(channels.size())) {
        return false;
    }
    for (const auto& elem : channels) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvChannelListReply::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // id
    size += sizeof(uint8_t); // channels
    size += ChannelInfo::size(); // channels
    return size;
}


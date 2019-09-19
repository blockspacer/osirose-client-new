#include "srv_inventory_data.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvInventoryData::Header& SrvInventoryData::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvInventoryData::Header::get_type() const {
    return data.type;
}

SrvInventoryData::Header& SrvInventoryData::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvInventoryData::Header::get_id() const {
    return data.id;
}

SrvInventoryData::Header& SrvInventoryData::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvInventoryData::Header::get_isCreated() const {
    return data.isCreated;
}

SrvInventoryData::Header& SrvInventoryData::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvInventoryData::Header::get_header() const {
    return data.header;
}

bool SrvInventoryData::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvInventoryData::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvInventoryData::Header::size() {
    return sizeof(data);
}

SrvInventoryData::Data& SrvInventoryData::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvInventoryData::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvInventoryData::Data::get_durability() const {
    return data.durability;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvInventoryData::Data::get_life() const {
    return data.life;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvInventoryData::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvInventoryData::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvInventoryData::Data::get_refine() const {
    return data.refine;
}

SrvInventoryData::Data& SrvInventoryData::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvInventoryData::Data::get_count() const {
    return data.count;
}

bool SrvInventoryData::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvInventoryData::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvInventoryData::Data::size() {
    return sizeof(data);
}

SrvInventoryData::Item& SrvInventoryData::Item::set_header(const SrvInventoryData::Header header) {
    this->header = header;
    return *this;
}

SrvInventoryData::Header SrvInventoryData::Item::get_header() const {
    return header;
}

SrvInventoryData::Item& SrvInventoryData::Item::set_data(const SrvInventoryData::Data data) {
    this->data = data;
    return *this;
}

SrvInventoryData::Data SrvInventoryData::Item::get_data() const {
    return data;
}

bool SrvInventoryData::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvInventoryData::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvInventoryData::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvInventoryData::SrvInventoryData() : CRosePacket(SrvInventoryData::PACKET_ID) {}

SrvInventoryData::SrvInventoryData(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int64_t(zuly)) {
        return;
    }
    for (size_t index = 0; index < MAX_ITEMS; ++index) {
        if (!reader.get_iserialize(items[index])) {
            return;
        }
    }
}

SrvInventoryData& SrvInventoryData::set_zuly(const int64_t zuly) {
    this->zuly = zuly;
    return *this;
}

int64_t SrvInventoryData::get_zuly() const {
    return zuly;
}

SrvInventoryData& SrvInventoryData::set_items(const std::array<SrvInventoryData::Item, MAX_ITEMS>& items) {
    this->items = items;
    return *this;
}

SrvInventoryData& SrvInventoryData::set_items(const Item& items, size_t index) {
    this->items[index] = items;
    return *this;
}

const std::array<SrvInventoryData::Item, MAX_ITEMS>& SrvInventoryData::get_items() const {
    return items;
}

const SrvInventoryData::Item& SrvInventoryData::get_items(size_t index) const {
    return items[index];
}

SrvInventoryData SrvInventoryData::create(const int64_t& zuly) {
    SrvInventoryData packet;
    packet.set_zuly(zuly);
    return packet;
}

SrvInventoryData SrvInventoryData::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvInventoryData(reader);
}

std::unique_ptr<SrvInventoryData> SrvInventoryData::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvInventoryData>(reader);
}

bool SrvInventoryData::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int64_t(zuly)) {
        return false;
    }
    for (const auto& elem : items) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvInventoryData::size() {
    size_t size = 0;
    size += sizeof(int64_t); // zuly
    size += Item::size() * MAX_ITEMS; // items
    return size;
}


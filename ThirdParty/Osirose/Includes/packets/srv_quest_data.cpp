#include "srv_quest_data.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvQuestData::Header& SrvQuestData::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvQuestData::Header::get_type() const {
    return data.type;
}

SrvQuestData::Header& SrvQuestData::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvQuestData::Header::get_id() const {
    return data.id;
}

SrvQuestData::Header& SrvQuestData::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvQuestData::Header::get_isCreated() const {
    return data.isCreated;
}

SrvQuestData::Header& SrvQuestData::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvQuestData::Header::get_header() const {
    return data.header;
}

bool SrvQuestData::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvQuestData::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvQuestData::Header::size() {
    return sizeof(data);
}

SrvQuestData::Data& SrvQuestData::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvQuestData::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvQuestData::Data& SrvQuestData::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvQuestData::Data::get_durability() const {
    return data.durability;
}

SrvQuestData::Data& SrvQuestData::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvQuestData::Data::get_life() const {
    return data.life;
}

SrvQuestData::Data& SrvQuestData::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvQuestData::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvQuestData::Data& SrvQuestData::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvQuestData::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvQuestData::Data& SrvQuestData::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvQuestData::Data::get_refine() const {
    return data.refine;
}

SrvQuestData::Data& SrvQuestData::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvQuestData::Data::get_count() const {
    return data.count;
}

bool SrvQuestData::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvQuestData::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvQuestData::Data::size() {
    return sizeof(data);
}

SrvQuestData::Item& SrvQuestData::Item::set_header(const SrvQuestData::Header header) {
    this->header = header;
    return *this;
}

SrvQuestData::Header SrvQuestData::Item::get_header() const {
    return header;
}

SrvQuestData::Item& SrvQuestData::Item::set_data(const SrvQuestData::Data data) {
    this->data = data;
    return *this;
}

SrvQuestData::Data SrvQuestData::Item::get_data() const {
    return data;
}

bool SrvQuestData::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvQuestData::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvQuestData::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvQuestData::Quest::get_id() const {
    return id;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_timer(const uint32_t timer) {
    this->timer = timer;
    return *this;
}

uint32_t SrvQuestData::Quest::get_timer() const {
    return timer;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_vars(const std::array<uint16_t, MAX_QUEST_VARS> vars) {
    this->vars = vars;
    return *this;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_vars(const uint16_t vars, size_t index) {
    this->vars[index] = vars;
    return *this;
}

std::array<uint16_t, MAX_QUEST_VARS> SrvQuestData::Quest::get_vars() const {
    return vars;
}

uint16_t SrvQuestData::Quest::get_vars(size_t index) const {
    return vars[index];
}

SrvQuestData::Quest& SrvQuestData::Quest::set_switches(const uint32_t switches) {
    this->switches = switches;
    return *this;
}

uint32_t SrvQuestData::Quest::get_switches() const {
    return switches;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_items(const std::array<SrvQuestData::Item, MAX_QUEST_ITEMS> items) {
    this->items = items;
    return *this;
}

SrvQuestData::Quest& SrvQuestData::Quest::set_items(const Item items, size_t index) {
    this->items[index] = items;
    return *this;
}

std::array<SrvQuestData::Item, MAX_QUEST_ITEMS> SrvQuestData::Quest::get_items() const {
    return items;
}

SrvQuestData::Item SrvQuestData::Quest::get_items(size_t index) const {
    return items[index];
}

bool SrvQuestData::Quest::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint32_t(timer)) {
        return false;
    }
    for (size_t index = 0; index < MAX_QUEST_VARS; ++index) {
        if (!writer.set_uint16_t(vars[index])) {
            return false;
        }
    }
    if (!writer.set_uint32_t(switches)) {
        return false;
    }
    for (size_t index = 0; index < MAX_QUEST_ITEMS; ++index) {
        if (!writer.set_iserialize(items[index])) {
            return false;
        }
    }
    return true;
}

bool SrvQuestData::Quest::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(id)) {
        return false;
    }
    if (!reader.get_uint32_t(timer)) {
        return false;
    }
    for (size_t index = 0; index < MAX_QUEST_VARS; ++index) {
        if (!reader.get_uint16_t(vars[index])) {
            return false;
        }
    }
    if (!reader.get_uint32_t(switches)) {
        return false;
    }
    for (size_t index = 0; index < MAX_QUEST_ITEMS; ++index) {
        if (!reader.get_iserialize(items[index])) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvQuestData::Quest::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint32_t); // timer
    size += sizeof(uint16_t) * MAX_QUEST_VARS; // vars
    size += sizeof(uint32_t); // switches
    size += Item::size() * MAX_QUEST_ITEMS; // items
    return size;
}


SrvQuestData::SrvQuestData() : CRosePacket(SrvQuestData::PACKET_ID) {}

SrvQuestData::SrvQuestData(CRoseReader reader) : CRosePacket(reader) {
    for (size_t index = 0; index < MAX_CONDITIONS_EPISODE; ++index) {
        if (!reader.get_uint16_t(episodes[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_CONDITIONS_JOB; ++index) {
        if (!reader.get_uint16_t(jobs[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_CONDITIONS_PLANET; ++index) {
        if (!reader.get_uint16_t(planets[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_CONDITIONS_UNION; ++index) {
        if (!reader.get_uint16_t(unions[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_QUESTS; ++index) {
        if (!reader.get_iserialize(quests[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_SWITCHES; ++index) {
        if (!reader.get_uint32_t(switches[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_WISHLIST; ++index) {
        if (!reader.get_iserialize(wishlist[index])) {
            return;
        }
    }
}

SrvQuestData& SrvQuestData::set_episodes(const std::array<uint16_t, MAX_CONDITIONS_EPISODE> episodes) {
    this->episodes = episodes;
    return *this;
}

SrvQuestData& SrvQuestData::set_episodes(const uint16_t episodes, size_t index) {
    this->episodes[index] = episodes;
    return *this;
}

std::array<uint16_t, MAX_CONDITIONS_EPISODE> SrvQuestData::get_episodes() const {
    return episodes;
}

uint16_t SrvQuestData::get_episodes(size_t index) const {
    return episodes[index];
}

SrvQuestData& SrvQuestData::set_jobs(const std::array<uint16_t, MAX_CONDITIONS_JOB> jobs) {
    this->jobs = jobs;
    return *this;
}

SrvQuestData& SrvQuestData::set_jobs(const uint16_t jobs, size_t index) {
    this->jobs[index] = jobs;
    return *this;
}

std::array<uint16_t, MAX_CONDITIONS_JOB> SrvQuestData::get_jobs() const {
    return jobs;
}

uint16_t SrvQuestData::get_jobs(size_t index) const {
    return jobs[index];
}

SrvQuestData& SrvQuestData::set_planets(const std::array<uint16_t, MAX_CONDITIONS_PLANET> planets) {
    this->planets = planets;
    return *this;
}

SrvQuestData& SrvQuestData::set_planets(const uint16_t planets, size_t index) {
    this->planets[index] = planets;
    return *this;
}

std::array<uint16_t, MAX_CONDITIONS_PLANET> SrvQuestData::get_planets() const {
    return planets;
}

uint16_t SrvQuestData::get_planets(size_t index) const {
    return planets[index];
}

SrvQuestData& SrvQuestData::set_unions(const std::array<uint16_t, MAX_CONDITIONS_UNION> unions) {
    this->unions = unions;
    return *this;
}

SrvQuestData& SrvQuestData::set_unions(const uint16_t unions, size_t index) {
    this->unions[index] = unions;
    return *this;
}

std::array<uint16_t, MAX_CONDITIONS_UNION> SrvQuestData::get_unions() const {
    return unions;
}

uint16_t SrvQuestData::get_unions(size_t index) const {
    return unions[index];
}

SrvQuestData& SrvQuestData::set_quests(const std::array<SrvQuestData::Quest, MAX_QUESTS>& quests) {
    this->quests = quests;
    return *this;
}

SrvQuestData& SrvQuestData::set_quests(const Quest& quests, size_t index) {
    this->quests[index] = quests;
    return *this;
}

const std::array<SrvQuestData::Quest, MAX_QUESTS>& SrvQuestData::get_quests() const {
    return quests;
}

const SrvQuestData::Quest& SrvQuestData::get_quests(size_t index) const {
    return quests[index];
}

SrvQuestData& SrvQuestData::set_switches(const std::array<uint32_t, MAX_SWITCHES> switches) {
    this->switches = switches;
    return *this;
}

SrvQuestData& SrvQuestData::set_switches(const uint32_t switches, size_t index) {
    this->switches[index] = switches;
    return *this;
}

std::array<uint32_t, MAX_SWITCHES> SrvQuestData::get_switches() const {
    return switches;
}

uint32_t SrvQuestData::get_switches(size_t index) const {
    return switches[index];
}

SrvQuestData& SrvQuestData::set_wishlist(const std::array<SrvQuestData::Item, MAX_WISHLIST> wishlist) {
    this->wishlist = wishlist;
    return *this;
}

SrvQuestData& SrvQuestData::set_wishlist(const Item wishlist, size_t index) {
    this->wishlist[index] = wishlist;
    return *this;
}

std::array<SrvQuestData::Item, MAX_WISHLIST> SrvQuestData::get_wishlist() const {
    return wishlist;
}

SrvQuestData::Item SrvQuestData::get_wishlist(size_t index) const {
    return wishlist[index];
}

SrvQuestData SrvQuestData::create() {
    SrvQuestData packet;
    return packet;
}

SrvQuestData SrvQuestData::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvQuestData(reader);
}

std::unique_ptr<SrvQuestData> SrvQuestData::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvQuestData>(reader);
}

bool SrvQuestData::pack(CRoseBasePolicy& writer) const {
    for (const auto& elem : episodes) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : jobs) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : planets) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : unions) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : quests) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    for (const auto& elem : switches) {
        if (!writer.set_uint32_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : wishlist) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvQuestData::size() {
    size_t size = 0;
    size += sizeof(uint16_t) * MAX_CONDITIONS_EPISODE; // episodes
    size += sizeof(uint16_t) * MAX_CONDITIONS_JOB; // jobs
    size += sizeof(uint16_t) * MAX_CONDITIONS_PLANET; // planets
    size += sizeof(uint16_t) * MAX_CONDITIONS_UNION; // unions
    size += Quest::size() * MAX_QUESTS; // quests
    size += sizeof(uint32_t) * MAX_SWITCHES; // switches
    size += Item::size() * MAX_WISHLIST; // wishlist
    return size;
}


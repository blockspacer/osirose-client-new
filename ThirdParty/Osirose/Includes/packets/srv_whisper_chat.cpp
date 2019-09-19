#include "srv_whisper_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvWhisperChat::SrvWhisperChat() : CRosePacket(SrvWhisperChat::PACKET_ID) {}

SrvWhisperChat::SrvWhisperChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(sender)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvWhisperChat& SrvWhisperChat::set_sender(const std::string& sender) {
    this->sender = sender;
    return *this;
}

const std::string& SrvWhisperChat::get_sender() const {
    return sender;
}

SrvWhisperChat& SrvWhisperChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvWhisperChat::get_message() const {
    return message;
}

SrvWhisperChat SrvWhisperChat::create(const std::string& sender, const std::string& message) {
    SrvWhisperChat packet;
    packet.set_sender(sender);
    packet.set_message(message);
    return packet;
}

SrvWhisperChat SrvWhisperChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvWhisperChat(reader);
}

std::unique_ptr<SrvWhisperChat> SrvWhisperChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvWhisperChat>(reader);
}

bool SrvWhisperChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(sender)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvWhisperChat::size() {
    size_t size = 0;
    return size;
}


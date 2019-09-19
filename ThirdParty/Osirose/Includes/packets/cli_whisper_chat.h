#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliWhisperChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_WHISPER_CHAT;
        CliWhisperChat();
        CliWhisperChat(CRoseReader reader);
        CliWhisperChat(CliWhisperChat&&) = default;
        CliWhisperChat& operator=(CliWhisperChat&&) = default;
        ~CliWhisperChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliWhisperChat& set_target(const std::string&);
        const std::string& get_target() const;
        CliWhisperChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliWhisperChat create(const std::string& target, const std::string& message);
        static CliWhisperChat create(const uint8_t* buffer);
        static std::unique_ptr<CliWhisperChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string target;
        std::string message;
};

}
}

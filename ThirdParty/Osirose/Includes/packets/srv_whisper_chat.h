#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvWhisperChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_WHISPER_CHAT;
        SrvWhisperChat();
        SrvWhisperChat(CRoseReader reader);
        SrvWhisperChat(SrvWhisperChat&&) = default;
        SrvWhisperChat& operator=(SrvWhisperChat&&) = default;
        ~SrvWhisperChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvWhisperChat& set_sender(const std::string&);
        const std::string& get_sender() const;
        SrvWhisperChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvWhisperChat create(const std::string& sender, const std::string& message);
        static SrvWhisperChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvWhisperChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string sender;
        std::string message;
};

}
}

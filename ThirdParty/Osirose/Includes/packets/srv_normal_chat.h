#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvNormalChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_NORMAL_CHAT;
        SrvNormalChat();
        SrvNormalChat(CRoseReader reader);
        SrvNormalChat(SrvNormalChat&&) = default;
        SrvNormalChat& operator=(SrvNormalChat&&) = default;
        ~SrvNormalChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvNormalChat& set_charId(const uint16_t);
        uint16_t get_charId() const;
        SrvNormalChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvNormalChat create(const uint16_t& charId, const std::string& message);
        static SrvNormalChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvNormalChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t charId;
        std::string message;
};

}
}

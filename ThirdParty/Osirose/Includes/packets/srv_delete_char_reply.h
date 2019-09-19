#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvDeleteCharReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_DELETE_CHAR_REPLY;
        SrvDeleteCharReply();
        SrvDeleteCharReply(CRoseReader reader);
        SrvDeleteCharReply(SrvDeleteCharReply&&) = default;
        SrvDeleteCharReply& operator=(SrvDeleteCharReply&&) = default;
        ~SrvDeleteCharReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvDeleteCharReply& set_remainingTime(const uint32_t);
        uint32_t get_remainingTime() const;
        SrvDeleteCharReply& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static SrvDeleteCharReply create(const uint32_t& remainingTime, const std::string& name);
        static SrvDeleteCharReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvDeleteCharReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t remainingTime;
        std::string name;
};

}
}

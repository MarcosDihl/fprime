/*
 * LogPacket.hpp
 *
 *  Created on: May 24, 2014
 *      Author: Timothy Canham
 */

#ifndef LOGPACKET_HPP_
#define LOGPACKET_HPP_

#include <Fw/Com/ComPacket.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>

namespace Fw {

    class LogPacket : public ComPacket {
        public:

            LogPacket();
            virtual ~LogPacket();

            SerializeStatus serialize(SerializeBufferBase& buffer) const; //!< serialize contents
            SerializeStatus deserialize(SerializeBufferBase& buffer);

            void setId(FwEventIdType id);
            void setLogBuffer(LogBuffer& buffer);
            void setTimeTag(Fw::Time& timeTag);

            FwEventIdType getId(void);
            Fw::Time& getTimeTag(void);
            LogBuffer& getLogBuffer(void);

        protected:
            FwEventIdType m_id; // !< Channel id
            Fw::Time m_timeTag; // !< time tag
            LogBuffer m_logBuffer; // !< serialized argument data
    };

} /* namespace Fw */

#endif /* LOGPACKET_HPP_ */

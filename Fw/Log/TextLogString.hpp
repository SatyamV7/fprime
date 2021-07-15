#ifndef FW_TEXT_LOG_STRING_TYPE_HPP
#define FW_TEXT_LOG_STRING_TYPE_HPP

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringType.hpp>
#include <FpConfig.hpp>
#include <Fw/Cfg/SerIds.hpp>

namespace Fw {

    class TextLogString : public Fw::StringBase {
        public:

            enum {
                SERIALIZED_TYPE_ID = FW_TYPEID_LOG_STR,
                SERIALIZED_SIZE = FW_LOG_TEXT_BUFFER_SIZE + sizeof(FwBuffSizeType) // size of buffer + storage of two size words
            };

            TextLogString(const char* src);
            TextLogString(const StringBase& src);
            TextLogString(const TextLogString& src);
            TextLogString();
            ~TextLogString();
            const char* toChar() const;
            NATIVE_UINT_TYPE length() const;

            const TextLogString& operator=(const TextLogString& other); //!< equal operator for other strings

            SerializeStatus serialize(SerializeBufferBase& buffer) const;
            SerializeStatus deserialize(SerializeBufferBase& buffer);

        private:
            NATIVE_UINT_TYPE getCapacity() const ;
            void terminate(NATIVE_UINT_TYPE size); //!< terminate the string

            char m_buf[FW_LOG_TEXT_BUFFER_SIZE];
    };

}

#endif

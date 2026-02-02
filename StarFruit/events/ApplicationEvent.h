#pragma once

#include "sfpch.h"
#include <Event.h>

namespace StarFruit
{
    class STARFRUIT_API WindowResizeEvent : public Event
    {
        public:
            WindowResizeEvent(unsigned int width, unsigned int height)
                : m_Width(width), m_Height(height) {}

            inline unsigned int GetWidth() const { return m_Width; }
            inline unsigned int GetHeight() const { return m_Height; }

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "WindowResizeEvent: Width=" << m_Width << ", Height=" << m_Height;
                return ss.str();
            }
            
            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(EventCategoryApp)

        private:
            unsigned int m_Width, m_Height;

    };

    class STARFRUIT_API WindowCloseEvent : public Event
    {
        public:
            WindowCloseEvent() {}
            EVENT_CLASS_TYPE(WindowClose)
            EVENT_CLASS_CATEGORY(EventCategoryApp)
    };

}

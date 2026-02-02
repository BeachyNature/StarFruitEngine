#pragma once

#include "sfpch.h"
#include <Core.h>

namespace StarFruit 
{

    enum EventCategory
    {
        None = 0,
        EventCategoryApp      = BIT(0),
        EventCategoryInput    = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse    = BIT(3),
        EventCategoryMouseBtn = BIT(4)
    };

    enum class EventType
    {
        None = 0,
        KeyPressed, KeyReleased,
        AppTick, AppUpdate, AppRender,
        WindowClose, WindowMoved, WindowResize, WindowFocus, WindowLostFocus,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

// Macros -------
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
#define EVENT_CLASS_TYPE(type)\
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

// end Macros --------------

    /*
    Defined Class to handle events as they are distributed.
    
    
    */
    class STARFRUIT_API Event
    {

        friend class EventDispatcher;

        public:
            virtual EventType GetEventType() const = 0;
            virtual int GetCategoryFlags() const = 0;
            virtual const char* GetName() const = 0;
            virtual std::string ToString() const { return GetName(); }

            // See if event belongs to a category
            inline bool IsInCategory(EventCategory category)
            {
                return GetCategoryFlags() & category;
            }
        
        protected:
            bool m_Handled = false;

    };

    /*
    Handle the event actions as they come in.
    
    */
    class EventDispatcher
    {
        template<typename T>
        using EventFunc = std::function<bool(T&)>;

        public:
            EventDispatcher(Event& event) : m_Event(event){}

            template<typename T>
            bool Dispatch(EventFunc<T> func)
            {
                if (m_Event.GetEventType() == T::GetStaticType())
                {
                    m_Event.m_Handled = func(*(T*)&m_Event);
                    return true;
                }
                return false;
            }

        private:
            Event& m_Event;

    };

    /*
    Convert event to format to view when logging.
    */
    inline std::string format_as(const Event& e)
    {
        return e.ToString();
    }

}

/* 
 * File:   event.h
 * Author: Nathan Hansen
 *
 * Created on March 7, 2012, 11:29 AM
 */

#ifndef EVENT_H
#define	EVENT_H

#include <list>

/**
 * This defines a MessageRecieved Event. The parameters are as follows<br />
 * void* caller: The object that this event is calling.<br />
 * void* params: The Params object that should be passed with this event.<br />
 * void* callee: The Sender
 */
typedef void(*EventFunction)(void* caller, void* params, void* callee);

/**
 * Simulate C# event the parameter T should be an function pointer.
 */

class event {
private:
    std::list<EventFunction> collection;
    
public:
        
    /**
     * Fire the events
     */
    void operator()() {
        std::list<EventFunction>::iterator it;
        for (it = collection.begin(); it != collection.end(); it++) {
            //Fire the event?
            (*it)();
        }
    }
    
    /**
     * Used to check if the collection is empty return the compiler's definition of NULL instead of 0 just to be safe.
     */
    int operator==() { return (0 == collection.size()) NULL : collection.size(); }
    
    /**
     * Adds an event to the event queue. It does not check to see if the event already exists. Be careful.
     * @param newEvent
     */
    void operator +=(EventFunction const newEvent) { collection.push_back(newEvent); }

    /**
     * Removes all instances of the event in the event queue.
     * @param existingEvent
     */
    void operator -=(EventFunction const existingEvent) { collection.remove(existingEvent); }
};

#endif	/* EVENT_H */


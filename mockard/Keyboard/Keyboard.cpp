#include "Keyboard.h"

#include <cstdint>
#include <cstddef>
#include <array>

Keyboard_::Keyboard_()
{
}

/**
 * @brief Initialize the global Keyboard Object
 */
void Keyboard_::begin(const uint8_t *layout)
{
    _asciimap = layout;
    keyLog = std::array<KeyReport, KEY_LOG_SIZE>();
    keyLogIndex = 0;
}

/**
 * @brief Gracefully destroy the global Keyboard Object
 */
void Keyboard_::end()
{
    // Do nothing
}

/**
 * @brief Mock sendReport implementation
 *
 * @details This fuction mocks the sendReport function of the Keyboard class
 *          by storing the key report in a circular buffer.
 */
void Keyboard_::sendReport(KeyReport *keys)
{
    keyLog[keyLogIndex] = *keys;
    keyLogIndex = (keyLogIndex + 1) % KEY_LOG_SIZE;
}

/**
 * @brief Write a single key to the Keyboard
 */
size_t Keyboard_::write(uint8_t k)
{
    KeyReport _keyReport;

    if (k >= 136)
    {
        return 0;
    }

    uint8_t modifiers = 0;
    if (k & 0x80)
    {
        modifiers |= 0x02;
        k &= 0x7F;
    }

    _keyReport.keys[0] = k;
    _keyReport.modifiers = modifiers;
    _keyReport.reserved = 0;

    sendReport(&_keyReport);
    return 1;
}

/**
 * @brief Write a buffer of keys to the Keyboard
 */
size_t Keyboard_::write(const uint8_t *buffer, size_t size)
{
    size_t result = 0;
    while (size--)
    {
        result += write(*buffer++);
    }
    return result;
}

/**
 * @brief Press a single key
 */
size_t Keyboard_::press(uint8_t k)
{
    return write(k);
}

/**
 * @brief Release a single key
 */
size_t Keyboard_::release(uint8_t k)
{
    return write(k | 0x80);
}

/**
 * @brief Release all keys
 */
void Keyboard_::releaseAll()
{
    KeyReport _keyReport;
    _keyReport.modifiers = 0;
    _keyReport.reserved = 0;
    for (size_t i = 0; i < 6; i++)
    {
        _keyReport.keys[i] = 0;
    }
    sendReport(&_keyReport);
}

/**
 * @brief Get the key log
 */
std::array<KeyReport, KEY_LOG_SIZE> Keyboard_::getKeyLog()
{
    return this->keyLog;
}
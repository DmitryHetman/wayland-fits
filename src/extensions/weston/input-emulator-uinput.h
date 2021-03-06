/*
 * Copyright © 2013 Intel Corporation
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the copyright holders not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.  The copyright holders make
 * no representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __INPUT_EMULATOR_UINPUT_H__
#define __INPUT_EMULATOR_UINPUT_H__

#include "input-emulator.h"

namespace wfits {
namespace weston {

class InputEmulatorUInput : public InputEmulator
{
public:
	InputEmulatorUInput();
	virtual ~InputEmulatorUInput();

	/*virtual*/ void movePointer(const int32_t x, const int32_t y) const;
	/*virtual*/ void keySend(const uint32_t key, const uint32_t state) const;

private:
	void writeEvent(struct input_event *event) const;

	int fd_;

	static bool registered_;
};

} // namespace weston
} // namespace wfits

#endif

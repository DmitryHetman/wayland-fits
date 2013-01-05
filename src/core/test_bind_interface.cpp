
#include "harness.h"

template <typename O, const wl_interface& interface, const std::string& str_interface>
class BindInterface : public CoreTestHarness
{
public:
	BindInterface()
		: CoreTestHarness::CoreTestHarness()
		, object_(NULL)
	{
		return;
	}

	void handleGlobal(uint32_t id, const std::string& iface, uint32_t)
	{
		if (iface == str_interface)
		{
			object_ = static_cast<O*>(
				wl_registry_bind(
					*this, id, &interface, 1
				)
			);
		}
	}
	
	void teardown()
	{
		FAIL_IF(object_ == NULL);
	}
private:
	O* object_;
};

#define BIND_TEST(name) \
	std::string str_iface_##name = #name; \
	typedef BindInterface<name, name##_interface, str_iface_##name> bind_ ## name; \
	WFITS_CORE_HARNESS_TEST_CASE(bind_ ## name, "BindInterface")

BIND_TEST(wl_compositor)
BIND_TEST(wl_display)
BIND_TEST(wl_shm)
BIND_TEST(wl_output)
BIND_TEST(wl_seat)
BIND_TEST(wl_shell)
BIND_TEST(wl_data_device_manager)
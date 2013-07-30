#include <boost/test/unit_test.hpp>
#include "libcql/cql.h"
#include "cql_error.hpp"
#include "cql_defines.hpp"
#include "cql_message_error.hpp"

BOOST_AUTO_TEST_SUITE(cql_message_error)

BOOST_AUTO_TEST_CASE(setters_and_getters)
{
	cql::cql_message_error_t m;
	m.code(1);
	m.message("foo");
	BOOST_CHECK_EQUAL(1, m.code());
	BOOST_CHECK_EQUAL("foo", m.message());
}

BOOST_AUTO_TEST_CASE(constructor)
{
	cql::cql_message_error_t m(1, "foo");
	BOOST_CHECK_EQUAL(1, m.code());
	BOOST_CHECK_EQUAL("foo", m.message());
}

BOOST_AUTO_TEST_CASE(opcode)
{
	cql::cql_message_error_t m;
	BOOST_CHECK_EQUAL(CQL_OPCODE_ERROR, m.opcode());
}

BOOST_AUTO_TEST_CASE(serialization_round_trip)
{
	std::stringstream output;
	cql::cql_message_error_t m(1, "foo");
    cql::cql_error_t err;
    m.prepare(&err);
    m.consume(&err);
	BOOST_CHECK_EQUAL("foo", m.message());
	BOOST_CHECK_EQUAL(1, m.code());
}

BOOST_AUTO_TEST_SUITE_END()

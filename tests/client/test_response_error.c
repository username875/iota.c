#include <stdio.h>
#include <unity/unity.h>

#include "client/api/response_error.h"

void test_deser_res_err() {
  char const* const json_err = "{ \"error\": { \"code\": 400, \"message\": \"invalid data provided\" } }";

  cJSON* json_obj = cJSON_Parse(json_err);
  TEST_ASSERT_NOT_NULL(json_obj);
  res_err_t* r = deser_error(json_obj);
  TEST_ASSERT_NOT_NULL(r);

  TEST_ASSERT_EQUAL_INT(400, r->code);
  TEST_ASSERT_EQUAL_STRING("invalid data provided", r->msg);

  res_err_free(r);
  cJSON_Delete(json_obj);
}

void test_deser_err_code_not_n() {
  char const* const json_err = "{ \"error\": { \"code\": \"400\", \"message\": \"invalid data provided\" } }";

  cJSON* json_obj = cJSON_Parse(json_err);
  TEST_ASSERT_NOT_NULL(json_obj);
  res_err_t* r = deser_error(json_obj);
  TEST_ASSERT_NULL(r);

  cJSON_Delete(json_obj);
}

void test_deser_err_msg_not_str() {
  char const* const json_err = "{ \"error\": { \"code\": 400, \"message\": 1234 } }";

  cJSON* json_obj = cJSON_Parse(json_err);
  TEST_ASSERT_NOT_NULL(json_obj);
  res_err_t* r = deser_error(json_obj);
  TEST_ASSERT_NULL(r);

  cJSON_Delete(json_obj);
}

void test_deser_err_not_obj() {
  char const* const json_err = "{ \"error\": \"invalid data provided\" }";

  cJSON* json_obj = cJSON_Parse(json_err);
  TEST_ASSERT_NOT_NULL(json_obj);
  res_err_t* r = deser_error(json_obj);
  TEST_ASSERT_NULL(r);

  cJSON_Delete(json_obj);
}

int main() {
  UNITY_BEGIN();

  // correct json format
  RUN_TEST(test_deser_res_err);
  // error code is not a number
  RUN_TEST(test_deser_err_code_not_n);
  // error message is not a string
  RUN_TEST(test_deser_err_msg_not_str);
  // error element not a json object
  RUN_TEST(test_deser_err_not_obj);

  return UNITY_END();
}

/*
** mrb_uuid.c - Uuid class
**
** Copyright (c) @kjunichi 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_uuid.h"

#include <uuid.h>

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_uuid_data;

static const struct mrb_data_type mrb_uuid_data_type = {
  "mrb_uuid_data", mrb_free,
};

static mrb_value
mrb_uuid_init(mrb_state *mrb, mrb_value self)
{
  mrb_uuid_data *data;
  char *str;
  int len;

  data = (mrb_uuid_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_uuid_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_uuid_data *)mrb_malloc(mrb, sizeof(mrb_uuid_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value
mrb_uuid_hello(mrb_state *mrb, mrb_value self)
{
  mrb_uuid_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value
mrb_uuid_uuid(mrb_state *mrb, mrb_value self)
{
  char *uuid_str;
  uuid_t *uuid;

  uuid_create(&uuid);
  uuid_make(uuid, UUID_MAKE_V4);
  uuid_str = NULL;
  uuid_export(uuid, UUID_FMT_STR, (void **)&uuid_str, NULL);
  uuid_destroy(uuid);
  return mrb_str_new_cstr(mrb, uuid_str);
}

void
mrb_mruby_uuid_gem_init(mrb_state *mrb)
{
  struct RClass *uuid;
  uuid = mrb_define_class(mrb, "Uuid", mrb->object_class);
  mrb_define_method(mrb, uuid, "initialize", mrb_uuid_init, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, uuid, "uuid", mrb_uuid_uuid, MRB_ARGS_NONE());
  DONE;
}

void
mrb_mruby_uuid_gem_final(mrb_state *mrb)
{
}

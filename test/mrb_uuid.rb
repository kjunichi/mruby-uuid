##
## Uuid Test
##

assert("Uuid.uuid") do
  assert_equal(36, Uuid.uuid.to_s.length)
end

#ifndef GUARD_SMN_CLOUD_API_H
#define GUARD_SMN_CLOUD_API_H

struct SmnCloudWork;
struct BtlObj;

struct BtlObj* SmnCloudNextTarget(struct SmnCloudWork* work);
struct BtlObj* SmnCloudPickTeleportTarget(struct SmnCloudWork* work);

#endif

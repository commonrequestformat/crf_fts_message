<?php
/**
 * @file
 * crf_fts_message.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crf_fts_message_user_default_permissions() {
  $permissions = array();

  // Exported permission: create fts_message content.
  $permissions['create fts_message content'] = array(
    'name' => 'create fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any fts_message content.
  $permissions['delete any fts_message content'] = array(
    'name' => 'delete any fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own fts_message content.
  $permissions['delete own fts_message content'] = array(
    'name' => 'delete own fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any fts_message content.
  $permissions['edit any fts_message content'] = array(
    'name' => 'edit any fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own fts_message content.
  $permissions['edit own fts_message content'] = array(
    'name' => 'edit own fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: view any unpublished fts_message content.
  $permissions['view any unpublished fts_message content'] = array(
    'name' => 'view any unpublished fts_message content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}

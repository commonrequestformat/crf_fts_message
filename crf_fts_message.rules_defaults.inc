<?php
/**
 * @file
 * crf_fts_message.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crf_fts_message_default_rules_configuration() {
  $items = array();
  $items['rules_email_ocha_focal_point_on_fts_message_submission'] = entity_import('rules_config', '{ "rules_email_ocha_focal_point_on_fts_message_submission" : {
      "LABEL" : "Email OCHA focal point on FTS Message submission",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "fts_message" : "fts_message" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-crf-request" ],
            "field" : "field_crf_req_contact"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-crf-request:field-crf-req-contact" ] },
            "ITEM" : { "current_contact" : "Current contact" },
            "DO" : [
              { "mail" : {
                  "to" : [ "current-contact:mail" ],
                  "subject" : "FTS message provided by [node:author:field-first-name] [node:author:field-last-name] for [node:field-cluster:name-field] in [node:field-crf-request:title]",
                  "message" : "Dear [current-contact:field-first-name] [current-contact:field-last-name],\\r\\n\\r\\nKindly note that [node:author:field-first-name] [node:author:field-last-name] has submitted an FTS message for [node:field-cluster:name-field] in the Information [node:field-crf-request:title] to the CRF website.\\r\\n\\r\\nKind regards.",
                  "from" : [ "node:author:mail" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  return $items;
}

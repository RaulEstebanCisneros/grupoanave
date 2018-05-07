<?php

/**
 * @file
 * Retrieve a sinister arrival info from nid.
 */

/**
 * Return data from sinister arrival.
 */
function sinister_ws_arrival_resource_retrieve($nid) {
  $node = node_load($nid);
  $arrival = array();
  $count = 0;

  if (!empty($node->field_fecha_arribo[LANGUAGE_NONE][0]['value'])) {
    $date = $node->field_fecha_arribo[LANGUAGE_NONE][0]['value'];
    $arrival['date'] = $date;
    $count++;
  }
  else {
    $arrival['date'] = NULL;
  }
  if (!empty($node->field_mapa_arribo[LANGUAGE_NONE][0]['lat'])) {
    $lat = $node->field_mapa_arribo[LANGUAGE_NONE][0]['lat'];
    $lng = $node->field_mapa_arribo[LANGUAGE_NONE][0]['lng'];
    $arrival['latitude'] = $lat;
    $arrival['longitude'] = $lng;
    $count++;
  }
  else {
    $arrival['latitude'] = NULL;
    $arrival['longitude'] = NULL;
  }

  // if ($count == 2) {
  if ($count >= 1) {
    $arrival['checked-arrival'] = TRUE;
  }
  else {
    $arrival['checked-arrival'] = FALSE;
  }

  return $arrival;
}
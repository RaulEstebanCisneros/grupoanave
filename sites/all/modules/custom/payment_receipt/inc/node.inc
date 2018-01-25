<?php

/**
 * Implements hook_node_submit().
 */
function payment_receipt_node_submit($node){
  if(empty($node ->nid)) {
    switch ($node ->type){
      case 'recibo_contrato':
        payment_receipt_receipt_node_insert_recibo_contrato();
        payment_receipt_receipt_number_increase();
        break;
    }
  }
}

/**
 * Helper function for sinister_node_insert when the node type is siniestro.
 */
function payment_receipt_receipt_node_insert_recibo_contrato() {

  $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
  
  if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio) == $payment_receipt_folio) {
    payment_receipt_receipt_number_increase();
  }
} 
	